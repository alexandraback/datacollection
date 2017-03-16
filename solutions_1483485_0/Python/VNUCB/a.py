lines = open('input.txt','r').readlines()
mapping = {"z":"q", "q":"z"}
sample_in = ["our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"]
sample_out = ["ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"]
for i in range(3):
	for j in range(len(sample_out[i])):
		mapping[sample_out[i][j]] = sample_in[i][j]
T = int(lines[0])
for i in range(1,T+1):
	line = lines[i].strip()
	out = ""
	for j in range(len(line)):
		out += mapping[line[j]]
	print "Case #" + str(i) + ": " + out
