import datetime

def main():
    fi = open('C-large.in')
    fo = open('C-large.out', 'w')
    t = int(fi.readline())
    
    for i in range(t):
        #start = datetime.datetime.now()
        m,n = (int(s) for s in fi.readline().strip().split())
        o = 0
        matched = []
        pmatched = {}
        
        for cm in range(m,n):
            s = str(cm)
            sl = len(s)
            for j in range(sl):
                mk = int(s[sl-1-j:] + s[:sl-1-j])
                if (mk > cm) and mk >= m and mk <= n:
                    _m = "%d-%d" % (cm, mk)
                    pmatched[_m]=0
            
        
        o = len(pmatched.keys()) 
        fo.write("Case #%d: %s\n" % (i+1, o))
        print "Case #%d: %s" % (i+1, o)
        #k = pmatched.keys()
        #k.sort() 
        #print k
        
        #took = datetime.datetime.now() - start 
        #print "Case #%d: %s | %s sec %s ms" % (i+1, o, took.seconds, took.microseconds)        

if __name__ == "__main__":
    main()