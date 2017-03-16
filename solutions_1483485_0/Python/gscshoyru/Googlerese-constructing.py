encrypted = ["ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"]
decrypted = ["our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"]

known_characters = {"q" : "z", "z" : "q"}

for enc, dec in zip(encrypted, decrypted):
    for echar, dchar in zip(enc, dec):
        known_characters[echar] = dchar

print known_characters
print len(known_characters)

for char in range(ord("a"), ord("z") + 1):
    cchar = chr(char)
    print cchar, cchar in known_characters, cchar in known_characters.values()