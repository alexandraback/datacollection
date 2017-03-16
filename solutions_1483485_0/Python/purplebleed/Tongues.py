import sys

strs = ["ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "our language is impossible to understand",
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "there are twenty six factorial possibilities",
        "de kr kd eoya kw aej tysr re ujdr lkgc jv",
        "so it is okay if you want to just give up"]

def main():
    
    d = {}
    for i in range(0,len(strs),2):
        for j in range(0,len(strs[i])):
            d[strs[i][j]] = strs[i+1][j]
    
    d['z'] = 'q'
    d['q'] = 'z'
    
    f = open('./test1', 'r')
    count = int(f.readline())
    for i in range(0,count):
        l = f.readline().rstrip("\n")
        ans = ""
        for c in l:
            ans += d[c]
        print "Case #%d: %s" %(i+1,ans)
    
main()