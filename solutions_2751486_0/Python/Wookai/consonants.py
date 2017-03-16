import sys

def is_consonant(c):
    return c not in 'aeiou'

def process_case():
    word, n = sys.stdin.readline().strip().split(' ')
    n = int(n)

    word_length = len(word)
    nb_consonants = [0] * word_length
    last_start = [-1] * word_length
    result = 0

    for i, c in enumerate(word):
        if i == 0:
            nb_consonants[i] = 1 if is_consonant(c) else 0
        else:
            nb_consonants[i] = (nb_consonants[i - 1] + 1) if is_consonant(c) else 0

        if nb_consonants[i] >= n:
            last_start[i] = i - n + 1
        elif i > 0:
            last_start[i] = last_start[i - 1]
            
        if last_start[i] >= 0:
            result += last_start[i] + 1

    return result

def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        result = process_case()
        print 'Case #%d: %s' % (i + 1, result)

if __name__ == '__main__':
    main()
