#!/usr/bin/python


google = 'ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyqee'
english = 'ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupazoo'
dictionary = {}

# use the reference text to build a translation dictionary
for i in range(len(google)):
	if google[i] not in dictionary:
		dictionary[google[i]] = english[i]

# 'z' is missing from google and 'q' is missing from english
# so bijection means that 'z' maps to 'q'.
dictionary['z'] = 'q'


def translate(source):
	"""Translate from Googlerese to English."""
	length = len(source)
	chars = [''] * length

	for i in range(length):
		if source[i] in dictionary:
			chars[i] = dictionary[source[i]]

		else:
			chars[i] = source[i]

	return ''.join(chars)


# let's jam!
in_file = open('2012-0-a.in', 'r')
tests = int(in_file.readline())
out_file = open('2012-0-a.out', 'w')

for test in range(1, tests + 1):
	source = in_file.readline().strip()
	output = 'Case #%d: %s\n' % (test, translate(source))
	out_file.write(output)

out_file.close()
in_file.close()
