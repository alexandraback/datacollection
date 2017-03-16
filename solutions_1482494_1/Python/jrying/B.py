import sys

infile = open('B-large (1).in')
outfile = open('out.txt', 'wb')

count = 0
result = 0
cases = int(infile.readline())

for case in range(0, cases):
    levels = int(infile.readline())
    star1 = [0]*levels
    star2 = [0]*levels
    current = [0]*levels
    for level in range(0, levels):
        inline = infile.readline().split(' ')
        star1[level] = int(inline[0])
        star2[level] = int(inline[1])
    star = 0
    impossible = 0
    result = 0
    while(1):
        mstar2 = min(star2)
        if(star >= mstar2):
            index = star2.index(mstar2)
            star2[index] = 5555
            star1[index] = 5555
            star += 2 - current[index]
            current[index] = 2
            result += 1
            continue
        mstar1 = min(star1)
        if(star >= mstar1):
            enum = [i for i, j in enumerate(star1) if j == mstar1]
            index = 0
            Mstar2 = 0
            for e in enum:
                if(star2[e] >= Mstar2):
                    index = e
                    Mstar2 = star2[e]
            star1[index] = 5555
            star += 1
            current[index] = 1
            result += 1
            continue
        if(mstar1 == 5555 and mstar2 == 5555):
            break
        impossible = 1
        break
    count += 1
    if impossible == 1:
        outfile.write('Case #'+str(count)+': Too Bad\n')
    else:
        outfile.write('Case #'+str(count)+': '+str(result)+'\n')

infile.close()
outfile.close()
