from sys import stdin

def keep_typing(probs, n):
    """
    >>> keep_typing([0.6, 0.6], 5)
    7.84

    """
    prob_right = reduce(lambda x,y:x*y, probs)
    result = (n-len(probs)+1) + (n+1)*(1-prob_right)
    return result

def enter(probs, n):
    """
    .>> enter([0.6, 0.6], 5)
    7
    """
    return n+2

def backspace(probs, n):
    """
    .>> backspace([0.6, 0.6], 5)
    [8.4, 8]
    """
    result = []
    prob_right = 1
    for i in range(len(probs)):
        result.append((len(probs)-i+(n-i)+1) + (n+1)*(1-prob_right))
        prob_right = prob_right * probs[i]
    return result

def main():
    N = int(stdin.readline())
    for case in range(1,N+1):
        [A,B] = [int(x) for x in stdin.readline().split()]
        probs = [float(x) for x in stdin.readline().split()]
        expected = [keep_typing(probs,B)] + backspace(probs,B) + [enter(probs,B)]
        print "Case #%d: %f" % (case, min(expected))

if __name__ == "__main__":
    main()
