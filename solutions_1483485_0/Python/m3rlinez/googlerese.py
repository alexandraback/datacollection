if __name__ == "__main__":
    known_words = [("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"),
                   ("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities"),
                   ("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up"),
                   ("q","z"),("z","q")]
    
    mapping = {}
    
    for word in known_words:
        if len(word[0]) != len(word[1]):
            print "Wrong wrong wrong!"
            exit(0)
        
        for i in range(len(word[0])):            
            mapping[word[0][i]] = word[1][i]
            
    print "MAPPING count=", len(mapping)
    
    for i in range(ord('a'), ord('z') + 1):
        print chr(i), " =>", mapping[chr(i)] if chr(i) in mapping else '(no match)'
        
    fi = open('A-small-attempt0.in','r')
    fo = open('googlerese.out', 'w')
    n = int(fi.readline())
    
    for i in range(1, n + 1):
        line = fi.readline().strip()
        ans = "Case #%d: " % i
        for ch in line:
            ans += (mapping[ch] if ch in mapping else '_')

        fo.write("%s\n" % ans)
        print ans
        
    fo.close()
    fi.close()
    
                   