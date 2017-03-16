def main():
    fi = open('A-small-attempt0.in')
    fo = open('A-small-attempt0.out', 'w')
    t = int(fi.readline())
    
    
    known_keys = "aoz q ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
    known_values = "yeq z our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up" 
    mappings = dict(zip(known_keys, known_values))
    for i in range(t):
        tc = fi.readline().strip()
        o = ''
        for c in tc:
            o = o + mappings[c]
        
        fo.write("Case #%d: %s\n" % (i+1, o))
        print "Case #%d: %s" % (i+1, o)        

if __name__ == "__main__":
    main()