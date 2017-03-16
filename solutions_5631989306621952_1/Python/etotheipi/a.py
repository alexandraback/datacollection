import itertools

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    word = IN.readline()[:-1]
    
    answer = word[0]
    for i in xrange(1, len(word)):
        if answer[0] > word[i]:
            answer = answer + word[i]
        else:
            answer = word[i] + answer
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
