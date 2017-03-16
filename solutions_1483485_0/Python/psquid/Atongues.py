g = "y qee"+"ejp mysljylc kd kxveddknmc re jsicpdrysi"+"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+"de kr kd eoya kw aej tysr re ujdr lkgc jv"+"z"
e = "a zoo"+"our language is impossible to understand"+"there are twenty six factorial possibilities"+"so it is okay if you want to just give up"+"q"

f = open("A-small-attempt0.in",'r')
T = int(f.readline())
i = 1
for l in f.readlines():
    print("Case #"+str(i)+": "+l.strip().translate(str.maketrans(g,e)))
    i += 1
