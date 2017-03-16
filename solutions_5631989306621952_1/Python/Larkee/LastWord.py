import string
alpha = dict()
for i in range(len(string.ascii_uppercase)):
    alpha[string.ascii_uppercase[i]] = i

def last_word(string):
    final_word = string[0]
    for char in string[1:]:
        if alpha[final_word[0]] <= alpha[char]:
            final_word = char + final_word
        else:
            final_word += char
    return final_word

with open('A-large.in', 'r') as ipf, open('lastWord.txt', 'w') as opf:
    source = ipf.read()
    lines = source.splitlines()
    N = int(lines[0])
    for i in range(N):
        opf.write('Case #' + str(i+1) + ": ")
        S = lines[i+1]
        opf.write(last_word(S) + "\n")
