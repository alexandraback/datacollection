mappings = {
    "yeq"                                          : "aoz",
    "ejp mysljylc kd kxveddknmc re jsicpdrysi"     : "our language is impossible to understand",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" : "there are twenty six factorial possibilities",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"    : "so it is okay if you want to just give up",
    "z"                                            : "q" }
    
char_map = {" ": " "}

for k in mappings:
    for (a, b) in zip(k, mappings[k]):
        if a in char_map and char_map[a] != b:
            print a, b, char_map[a]
        char_map[a] = b

for c in "abcdefghijklmnopqrstuvwxyz ":
    assert c in char_map

with open("test_case", "r") as f:
    count = int(f.readline().strip())
    for case in range(1, count + 1):
        line = f.readline().strip()
        print "Case #" + str(case) + ": " + "".join(char_map[c] for c in line)
        
