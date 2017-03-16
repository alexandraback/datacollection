inp="""
ejp mysljylc kd kxveddknmc re jsicpdrysi
 rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
 de kr kd eoya kw aej tysr re ujdr lkgc jv
"""
outp="""
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
"""

strippedinp="".join(inp.split())
strippedoutp="".join(outp.split())
gtoe={'y':'a','q':'z','e':'o',' ':' '}
for (i,c) in enumerate(strippedinp):
    gtoe[c]=strippedoutp[i]

#Ran once in the interactive shell and the hard coded it back 
#>>> len(gtoe)
#26
#>>> "".join(sorted(gtoe.keys()))
#'abcdefghijklmnopqrstuvwxy'
#Ran human search to notice missing key is 'z'
#>>> "".join(sorted(gtoe.values()))
#'abcdefghijklmnoprstuvwxyz'
#Ran human search to notice missing value is 'q'
gtoe['z']='q'

for case in range(input()):
    print "Case #"+str(case+1)+":",
    print "".join(gtoe[c] for c in raw_input())
