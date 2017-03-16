f = open("a-small-attempt0.in", "r")
outf = open("a-small.out", "w")

sample_cipher = "y qee" +"ejp mysljylc kd kxveddknmc re jsicpdrysi" +"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" +"de kr kd eoya kw aej tysr re ujdr lkgc jv"

sample_plain = "a zoo" +"our language is impossible to understand" +"there are twenty six factorial possibilities" +"so it is okay if you want to just give up"


key = {}
alpha = "abcdefghijklmnopqrstuvwxyz"

print len(sample_cipher)
print len(sample_plain)

for i in range(len(sample_cipher)):
    c = sample_cipher[i]
    p = sample_plain[i]
    if c in alpha:
        if c in key:
            if p != key[c]:
                print "Error!!!", c, p, key[c]
        else:
            key[c] = p

for c in alpha:
    if c not in key.keys():
        break

for p in alpha:
    if p not in key.values():
        break

print c, p
key[c] = p
print len(key)


t = int( f.readline() )
cipher = []
for t1 in range(t):
    line = f.readline()
    cipher.append( line )

print len(cipher)

for t1 in range(t):
    text = ""
    for c in cipher[t1]:
        if c in key:
            text += key[c]
        else:
            text += c
    outf.write("Case #" + str(t1+1)+": " + text)
outf.close()
