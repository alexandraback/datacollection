#############
# Google Code Jam 2012
# Speaking in Tongues by Jos Kraaijeveld
# facebook.com/Kaidenceq @JMKraaijeveld
# kaidence.org
#############

import sys

# Our translation dictionary
dict = { 'a':'y', 'b':'h', 'c':'e', 'd':'s', 'e':'o', 'f':'c',
		 'g':'v', 'h':'x', 'i':'d', 'j':'u', 'k':'i', 'l':'g',
		 'm':'l', 'n':'b', 'o':'k', 'p':'r', 'q':'z', 'r':'t', 
		 's':'n', 't':'w', 'u':'j', 'v':'p', 'w':'f', 'x':'m',
		 'y':'a', 'z':'q' }

# Open the files and read the arguments
input = open(sys.argv[1])
output = open(sys.argv[2], 'w')
num_cases = int(input.readline())
current = 1

# Loop over the amount of testcases
while current <= num_cases:
	out_string = ""
	for char in input.readline():
		# If the character is in our dictionary, take the translated character
		# Otherwise, simply copy the character
		if char in dict:
			out_string += dict[char]
		else:
			out_string += char

	output.write("Case #{}: {}".format(current, out_string))
	current += 1
		

input.close()
output.close()

