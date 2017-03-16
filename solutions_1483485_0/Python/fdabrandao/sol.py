s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
s2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

alpha = map(chr, range(ord('a'), ord('z')+1))

for c in alpha:
    if c not in s1:
        print c, "missing in s1!"        

print

for i in range(ord('a'), ord('z')+1):
    c = chr(i)
    if c not in s2:
        print c, "missing in s2!"   

print '---'   
        
def test_map(m):              
    for c in alpha:
        if c not in m:
            print c, "missing in m!"               
        else:
            print c, m[c], c == m[c]                             

m = {}
for i in xrange(len(s1)):        
    m[s1[i]] = s2[i] 
m['z'] = 'q'
m['q'] = 'z'
m[' '] = ' '
test_map(m)

def read_input(fname):
    f = open(fname, "r")    
    return f.readlines()[1:]

def translate(m, s):
    res = ""
    for c in s:
        if c in m:
            res += m[c]
    return res

text = read_input("A-small-attempt0.in")
f = open("output.txt", "w")
for i in xrange(len(text)):
    trans = translate(m, text[i])
    if trans != "":
        print >>f, "Case #%d: %s" % (i+1, trans)

