f = open('dict.txt','r')
d = []
for line in f:
  d.append(line.upper()[0:len(line)-2])
f.close()
d = frozenset(d)

f = open('A-small-attempt1.in','r')
text = f.read()
f.close()

key = {}

ggl = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
eng = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

for i in range(len(ggl)):
  if ggl[i] == ' ': continue
  key[ggl[i]] = eng[i].upper()

key['q'] = 'Z'
key['z'] = 'Q'

for k in key:
  text = text.replace(k,key[k])
text = text.lower()

text = text.split('\n')

n = int(text[0])
text = text[1:]

text.pop()

string = ""
for i in range(n):
  string+= "Case #" + str(i+1) + ": " + text[i] + "\n"

f = open('out','w')
print string
f.write(string)
f.close()
