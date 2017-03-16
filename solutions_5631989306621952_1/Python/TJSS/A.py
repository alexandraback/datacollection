__author__ = 'tegjyot'

import fileinput

def LASTWORD(word):
    last_word=[]
    last_word.append(word[0])
    for s in word[1:]:

        if s>=last_word[0]:
            last_word.insert(0,s)
        else:
            last_word.append(s)
    return ''.join(last_word)


if __name__ == "__main__":
    f = fileinput.input()
    T=int(f.readline())
    for case in range(1,T+1):
         word= f.readline().strip()
         last_word=LASTWORD(word)
         print("Case #{0}: {1}".format(case, last_word))