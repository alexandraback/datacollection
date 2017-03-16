fin = open("A-small-attempt0.in","r");
fout = open("A-out","w")

size = int(fin.readline())

lines = fin.readlines()

fin.close()

dict = {'k':'i','e':'o','p':'r','m':'l','y':'a', 's':'n', 'l':'g', 'j':'u' , 'q':'z', 'c':'e', 'd':'s', 'x':'m','v':'p', 'n':'b', 'r':'t', 'i':'d','t':'w', 'h':'x', 'w':'f','b':'h', 'f':'c','u':'j', 'o':'k','a':'y','g':'v', 'z':'q'}
i=0;
for line in lines:
	i+=1
	line = line.rstrip('\n')
	line_t = ""
	for c in line:
		if str.isspace(c):
			line_t += c
		else: line_t += dict[c]
	fout.write( "Case #" + str(i) + ": " + line_t +'\n')
		
	
