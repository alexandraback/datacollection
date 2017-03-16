def keep_typing(A, B, p):
    '''(int, int, list) -> float
    Given the number of characters typed A, total number of characters
    in the password B, and probabilities of typing the ith letter of the
    password correctly p, return the expected number of keystrokes
    needed to correctly type the password, given that the user keeps
    typing.
    '''
    prob_correct = 1
    for i in range(A):
        prob_correct *= p[i]
    prob_incorrect = 1 - prob_correct
    
    return prob_correct * (B - A + 1) + prob_incorrect * ((2 * B) - A + 2)
    
    
def backspace(A, B, p, n):
    '''(int, int, list, int) -> float
    Given everything as in the other two functions and the number of
    backspaces that the user intends to make, returns the expected
    number of keystrokes the user is expected to make to get the
    password correctly.
    '''
    i = 0
    prob_correct = 1.0
    while i < A - n:
        prob_correct *= p[i]
        i += 1
    prob_incorrect = 1 - prob_correct
    
    return prob_correct * ((2 * n) + B - A + 1) \
            + prob_incorrect * ((2 * n) + (2 * B) - A + 2)
    
    
def give_up(A, B, p):
    '''(int, int, list) -> float
    Returns the expected number of keystrokes needed to correctly type
    the password, if the person just presses 'Enter' right away and
    retypes the whole thing.
    '''
    return float(B + 2)
    
if __name__ == "__main__":
    f = open('A-small-attempt0.in')
    num_test_cases = int(f.readline())
    c = 0
    
    output = open('A-small-output.txt', 'w')
    
    while c < num_test_cases:
        A, B = f.readline().split()
        A, B = int(A), int(B)
        print A, B
        
        probs = f.readline().split()
        probs = [float(p) for p in probs]
        assert len(probs) == A
        
        e = min(keep_typing(A, B, probs), give_up(A, B, probs))
        
        for n in range(A):
            t = backspace(A, B, probs, n + 1)
            if t < e:
                e = t
        
        case = "Case #{}: " .format(c + 1)
        expected = "%.6f" % e
        output.write(case + expected + '\n')
        
        c += 1