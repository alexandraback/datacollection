import sys

dict = {'y': 'a', 'e': 'o', 'q': 'z'}

tongues = ["ejp mysljylc kd kxveddknmc re jsicpdrysi",
           "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
           "de kr kd eoya kw aej tysr re ujdr lkgc jv"]

original = ["our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up",]

for i, t in enumerate(tongues):
    for j, c1 in enumerate(original[i]):
        dict[t[j]] = c1

letters = set(list(" abcdefghijklmnopqrstuvwxyz"))
keys    = set(dict.keys())
vals    = set(dict.values())

dict[list(letters - keys)[0]] = list(letters - vals)[0]

kases = int(sys.stdin.readline())
for k, l in enumerate(sys.stdin.readlines()):
    print("Case #%d: %s" % (k + 1, "".join(map(lambda c: dict[c], l.strip()))))
