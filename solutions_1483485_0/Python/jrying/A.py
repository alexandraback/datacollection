import sys

infile = open('A-small-attempt0 (2).in')
outfile = open('out.txt', 'wb')
#app = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ']
mapp = ['y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q']


infile.readline()
a = ord('a')
i = 0
for line in infile.readlines():
    result = ""
    for char in line:
        if(char.isalpha()):
            result += mapp[ord(char)-a]
        else:
            result += char
    i = i + 1
    outfile.write('Case #'+str(i)+': '+result)

infile.close()
outfile.close()
