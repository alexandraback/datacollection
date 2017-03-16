import string

coded = ("ejp mysljylc kd kxveddknmc re jsicpdrysi "
         "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd "
         "de kr kd eoya kw aej tysr re ujdr lkgc jv y e q z")
decoded = ("our language is impossible to understand "
           "there are twenty six factorial possibilities "
           "so it is okay if you want to just give up a o z q")
fro = []
to = []
for c,d in zip(coded, decoded):
    if c in fro: continue
    assert d not in to
    fro.append(c)
    to.append(d)
trans = string.maketrans(''.join(fro), ''.join(to))


def decode(line):
    return line.translate(trans)

def main():
    import sys
    data = open(sys.argv[1]+'.in').readlines()
    out = open(sys.argv[1]+'.out', 'w')

    t = int(data[0].strip())
    for i, line in enumerate(data[1:]):
        code = line.strip()
        answer = "Case #%i: %s\n" % (i+1, decode(code))
        out.write(answer)
        print answer

    out.close()

if __name__ == "__main__":
    main()

