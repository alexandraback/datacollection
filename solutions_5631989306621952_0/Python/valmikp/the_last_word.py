


filename = "A-small-attempt0.in"
f = open(filename, "r")
content = [x.strip('\n') for x in f.readlines()]
f.close()

f = open("output_A_1.out","w+")

for i,x in enumerate(content[1:]):
	count = 0
	final_word = content[i+1][0]
	for y in range(1,len(content[i+1])):
		if content[i+1][y] >= final_word[0]:
			final_word = content[i+1][y] + final_word
		else:
			final_word = final_word + content[i+1][y]

	f.write("Case #" + str(i+1) + ": " + final_word +"\n")

f.close()