from operator import itemgetter

'''
Created on Apr 14, 2012

@author: Fantoccini
'''

f = []
f.extend(['e', 't', 'a', 'o', 'i'])
f.extend(['n', 's', 'r', 'h', 'l'])
f.extend(['d', 'c', 'u', 'm', 'f'])
f.extend(['p', 'g', 'w', 'y', 'b'])
f.extend(['v', 'k', 'x', 'j', 'q'])
f.extend(['z'])

fo = []
fo.extend(['e', 't', 'a', 'o', 'i'])
fo.extend(['n', 's', 'r', 'h', 'l'])
fo.extend(['d', 'c', 'u', 'm', 'f'])
fo.extend(['p', 'g', 'w', 'y', 'b'])
fo.extend(['v', 'k', 'x', 'j', 'q'])
fo.extend(['z'])

m = {}
m = {'a':'y', 'b':'h', 'c':'e', 'd':'s', 'e':'o',
     'f':'c', 'g':'v', 'h':'x', 'i':'d', 'j':'u',
     'k':'i', 'l':'g', 'm':'l', 'n':'b', 'o':'k',
     'p':'r', 'q':'z', 'r':'t', 's':'n', 't':'w',
     'u':'j', 'v':'p', 'w':'f', 'x':'m', 'y':'a',
     'z':'q'
     }



freq = {}
freq2 = {}
freq3 = {}
freqd = {}
freq2w = {}
freq3w = {}
freq4w = {}


fin = open("c.in", "r")
fout = open("c.out", "w")
n = int (fin.readline())
case = []

for i in range(n):
    line = fin.readline()
    line = line.strip("\n")
    case.append(line)
    for j in range(len(line)):
        if line[j] == ' ':
            continue        
        if not line[j] in freq:
            freq[line[j]] = 0
        freq[line[j]] += 1
        if j == len(line) - 1:
            continue
        if line[j + 1] == ' ':
            continue
        if not line[j:j + 2] in freq2:
            freq2[line[j:j + 2]] = 0
        freq2[line[j:j + 2]] += 1
        if line[j] == line[j + 1]:
            if not line[j:j + 2] in freqd:
                freqd[line[j:j + 2]] = 0
            freqd[line[j:j + 2]] += 1
        if j == len(line) - 2:
            continue
        if line[j + 2] == ' ':
            continue
        if not line[j:j + 3] in freq3:
            freq3[line[j:j + 3]] = 0
    words = line.split()
    for word in words:
        if len(word) == 2:
            if not word in freq2w:
                freq2w[word] = 0
            freq2w[word] += 1
        if len(word) == 3:
            if not word in freq3w:
                freq3w[word] = 0
            freq3w[word] += 1
        if len(word) == 4:
            if not word in freq4w:
                freq4w[word] = 0
            freq4w[word] += 1

print "f"
lf = sorted(freq.items(), key=itemgetter(1), reverse=True)
print lf
print "f2"
lf2 = sorted(freq2.items(), key=itemgetter(1), reverse=True)
print lf2[0:30]
print "f3"
lf3 = sorted(freq3.items(), key=itemgetter(1), reverse=True)
print lf3[0:20]
print "fd"
lfd = sorted(freqd.items(), key=itemgetter(1), reverse=True)
print lfd[0:10]
print "f2w"
lf2w = sorted(freq2w.items(), key=itemgetter(1), reverse=True) 
print lf2w[0:20]
print "f3w"
lf3w = sorted(freq3w.items(), key=itemgetter(1), reverse=True)
print lf3w[0:40]
print "f4w"
lf4w = sorted(freq4w.items(), key=itemgetter(1), reverse=True)
print lf4w[0:30]

if m == {}:
    for i in range(len(lf)):
        k, v = lf[i]
        m[k] = f[i]
    
for i in range(n):
    stout = ""
    for j in range(len(case[i])):
        if case[i][j] == ' ':
            stout += ' '
        else:
            stout += m[case[i][j]]
    fout.write("Case #" + str (i+1) + ": " + stout + "\n")

fin.close()
fout.close()
