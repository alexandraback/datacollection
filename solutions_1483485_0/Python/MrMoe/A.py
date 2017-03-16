
mapping = {}


def store(a, b):
    if a in mapping:
        if mapping[a] != b:
            raise Exception
    else:
        mapping[a] = b


map(store, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand")
map(store, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities")
map(store, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up")
map(store, "y qee z", "a zoo q")


T = int(raw_input())

for t in range(T):
    inp = raw_input()
    
    out = map(lambda x: mapping[x], inp)
    
    print "Case #"+str(t+1)+":", "".join(out)



