vowels = ['a', 'e', 'i', 'o', 'u']

for t in range(input()):
    print "Case #%s:" % str(t + 1),
    input = raw_input().split()
    l = int(input[1])
    name = input[0]
    found = []
    substrs = 0
    for i in range(len(name)):
        j = 0
        try:
            while j < l and name[i + j] not in vowels:
                j += 1
            if j >= l:
                found.append(i)
        except IndexError:
            pass
    for i in range(len(name)):
        for j in range(len(name)):
            for k in found:
                if i <= k and k + l - 1 <= j:
                    substrs += 1
                    break

    print substrs
