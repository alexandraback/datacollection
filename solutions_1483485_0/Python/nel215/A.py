#coding:utf-8

def prepro():
    trans = {}
    inp = ["y qee",
           "ejp mysljylc kd kxveddknmc re jsicpdrysi",
           "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
           "de kr kd eoya kw aej tysr re ujdr lkgc jv"]
    out = ["a zoo",
           "our language is impossible to understand",
           "there are twenty six factorial possibilities",
           "so it is okay if you want to just give up"]
    for i in xrange(len(inp)):
        s,t = inp[i],out[i]
        for j in xrange(len(s)):
            a,b = s[j],t[j]
            trans[a] = b
    trans['z'] = 'q'
    return trans

def main():
    trans = prepro()
    N = int(raw_input())
    for c in xrange(1,N+1):
        res = ""
        inp = raw_input()
        for i in xrange(len(inp)):
            res += trans.get(inp[i])
        print "Case #"+str(c)+": "+res
  
if __name__=="__main__":
    main()
    