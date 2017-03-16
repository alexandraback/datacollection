import sys

train_lines = ["ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
              "de kr kd eoya kw aej tysr re ujdr lkgc jv"]

translated_lines = ["our language is impossible to understand","there are twenty six factorial possibilities",
                    "so it is okay if you want to just give up"]

known_mapping = {'y' : 'a', 'e' : 'o', 'q' : 'z', ' ': ' '}


i = 0
while i < len(train_lines):
    j = 0
    while j < len(train_lines[i]):
        if train_lines[i][j] not in known_mapping:
            known_mapping[train_lines[i][j]] = translated_lines[i][j]
        j+=1
    i+=1

alphas = map(chr, range(97, 123))

unknown_letters = [x for x in alphas if x not in known_mapping.keys()]
unknown_translations = [x for x in alphas if x not in known_mapping.values()]

known_mapping[unknown_letters[0]]= unknown_translations[0]



lines = file(sys.argv[1]).readlines()

i = 1
count = int(lines[0])

while i < len(lines):
    print "Case #"+str(i)+": " + "".join([known_mapping[ch] for ch in lines[i][:-1]])
    i+=1