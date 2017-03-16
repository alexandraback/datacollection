
from sys import argv

if __name__ == "__main__":
	mapping = {}
	mapping['y'] = 'a'
	mapping['e'] = 'o'
	mapping['q'] = 'z'
	mapping['z'] = 'q'	

	s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
	s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
	s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv"

	r1 = "our language is impossible to understand"
	r2 = "there are twenty six factorial possibilities"
	r3 = "so it is okay if you want to just give up"

	i = 0
	for c in s1:
		mapping[c] = r1[i]
		i += 1

	i = 0
	for c in s2:
		mapping[c] = r2[i]
		i += 1

	i = 0
	for c in s3:
		mapping[c] = r3[i]
		i += 1

	input = open(argv[1], 'r')
	output = open(argv[2], 'w')
	n = int(input.readline())
	i = 1
	for line in input:
		
		line = line.strip()
		res = ""
		for c in line:
			if c in mapping:
				res += mapping[c]
			else:
				res += c

		print >> output, "Case #" + str(i) + ": " + res
		i += 1

	input.close()
	output.close()