to = (
"our language is impossible to understand" +
"there are twenty six factorial possibilities" +
"so it is okay if you want to just give up")
fr = (
"ejp mysljylc kd kxveddknmc re jsicpdrysi" +
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" +
"de kr kd eoya kw aej tysr re ujdr lkgc jv")

#'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'.
map = { }
map.update({'y' : 'a', 'e' : 'o', 'q' : 'z', 'z' : 'q' })
for x, y in zip(fr, to): map[x] = y
#print (map, sorted(map), sorted(map.values()), len(map))
import sys
inp = sys.stdin
out = sys.stdout
n = int(inp.readline())
for i, l in enumerate(inp.readlines()):
    out.write("Case #" + str(i + 1) + ": " +
        "".join([map[x] if x in map else x for x in l]))

