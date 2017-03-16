#Henry Maltby
#Code Jam 2016

def last_word(S):
    """
    Sorts smaller letters to the right and larger (or =) letters to the left.
    """
    word = S[0]
    if len(S) == 1:
        return word
    for c in S[1:]:
        if c < word[0]:
            word = word + c
        else:
            word = c + word
    return word

f = open('A-small.in')
g = open('A-small.out', 'w')

T = int(f.readline())

for i in range(T):
    S = f.readline()
    g.write("Case #" + str(i + 1) + ": " + last_word(S))