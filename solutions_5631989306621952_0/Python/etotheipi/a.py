import itertools

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    word = IN.readline()[:-1]
    
    perms = list()
    
    for b in itertools.product([True, False], repeat = len(word)-1):
        last = word[0]
        for i in xrange(1, len(word)):
            if b[i-1]:
                last = last + word[i]
            else:
                last = word[i] + last
        perms.append(last)
        
    perms.sort()
    answer = perms[-1]
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
