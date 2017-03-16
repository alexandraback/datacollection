import string

def earliestRepeatIndex(target):
    return  min(i for i in range(1, len(target)+1) if target[i:] == target[:len(target)-i])

def solve(keyboard, target, S):
    prob = 1
    for letter in target:
        prob *= keyboard.count(letter) / float(len(keyboard))
    expected_typings = prob*(S-len(target)+1)

    earliest = earliestRepeatIndex(target)
    max_potential = (S - (len(target) - earliest)) / earliest if prob > 1e-9 else 0

    print "keyboard {} target {} S{} max_potential {} expected {}".format(keyboard, target, S, max_potential, expected_typings)
    return max_potential - expected_typings


def test(inputs, ans):
	b = solve(*inputs)
	if (b != ans):
		print "Failed test! Inputs {} should give answer of {} not {}".format(' '.join(inputs), ans, b)

def main():

    outfile = open('a.out','w')
    T = int(string.strip(raw_input()))    

    for k in xrange(1,T+1):
        print k
        K, L, S = map(int,string.strip(raw_input()).split())
        keyboard = raw_input().strip()
        target = raw_input().strip()

        answer = solve(keyboard, target, S) # add appropriate arguments
        outfile.write('Case #%d: %s\n' % (k,answer))

if __name__ == '__main__':
    main()