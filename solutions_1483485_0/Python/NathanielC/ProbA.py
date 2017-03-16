#doing everything backwards since that's the form
#the problem takes.
inp="""ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""
res="""our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""

alphabet_in="abcdefghijklmnopqrstuvwxyz"
alphabet_out=""

"""
for c in alphabet_in:
	if( inp.count(c)==0 ):
		alphabet_out+='?'
		continue;
	n = inp.index(c)
	alphabet_out+=res[n]

print alphabet_in
print alphabet_out
print ''.join(sorted(alphabet_out))
# "abcdefghijklmnopqrstuvwxyz"
# "yhesocvxduiglbkr?tnwjpfma?"
# q,z undefined... see problem: q<-z...
# onto / one to one, so z maps then to q.
"""
from string import maketrans
from string import translate

alphabet_out="yhesocvxduiglbkrztnwjpfmaq"

trans = maketrans(alphabet_in,alphabet_out)

#s = raw_input()
f = open("in.in")
l=f.readlines()
for i in xrange(1,len(l)):
    print 'Case #'+str(i)+': '+translate(l[i],trans)

#print s
