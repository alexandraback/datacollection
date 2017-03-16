englify = {
	'a' : 'y',
	'b' : 'h',
	'c' : 'e',
	'd' : 's',
	'e' : 'o',
	'f' : 'c',
	'g' : 'v',
	'h' : 'x',
	'i' : 'd',
	'j' : 'u',
	'k' : 'i',
	'l' : 'g',
	'm' : 'l',
	'n' : 'b',
	'o' : 'k',
	'p' : 'r',
	'q' : 'z',
	'r' : 't',
	's' : 'n',
	't' : 'w',
	'u' : 'j',
	'v' : 'p',
	'w' : 'f',
	'x' : 'm',
	'y' : 'a',
	'z' : 'q',
}

f = open('input.in','r')
o = open('output.txt', 'w+')

numtests = int(f.readline())
testcount = 0

while testcount < numtests:
  testcount += 1
  translated = ''
  line = f.readline()
  for x in line:
    if x in englify: translated += englify[x]
    else: translated += x
  o.write('Case #'+str(testcount)+': '+translated)
  #print 'Case #'+str(testcount)+': '+str(results)