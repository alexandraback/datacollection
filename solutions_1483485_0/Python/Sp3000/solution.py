key1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv z q"
key2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up q z"
count = 0
outfile = open("asmall_out.txt", "w")
for line in open("A-small-attempt0.in", "rU"):
    if count != 0:
        output = ""
        for letter in line:
            if letter in key1:
                output += key2[key1.index(letter)]
            else:
                print letter
        outfile.write("Case #" + str(count) + ": " + output + "\n")
    count += 1

outfile.close()
