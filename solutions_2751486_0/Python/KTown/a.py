
alpha = list("abcdefghijklmnopqrstuvwxyz")
const = list("abcdefghijklmnopqrstuvwxyz") 
vowel = list("aeiou")

tests = input()

for t in range(1,tests+1):
    line = raw_input().split()
    n = int(line[1])
    word = line[0]

    size = len(word)
    locs = []
    count = 0
    for i in range(size):
        if(count >= n):
            locs.append(i - n)
        if not word[i] in vowel:
            count = count + 1
        else:
            count = 0
    if(count >= n):
        locs.append(size - n)
    nVal = 0
    for i in range(size):
        closest = -1
        for a in locs:
            if a >= i:
                closest = a
                break
        if closest == -1:
            continue
        nVal = nVal + (size - (closest + n)+1)
    print "Case #" + repr(t) + ": " + repr(nVal)
