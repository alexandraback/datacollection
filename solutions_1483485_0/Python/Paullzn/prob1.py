#!/usr/bin/env python

dictionary = {}

def init():
    input = []
    output = []
    input.append('ejp mysljylc kd kxveddknmc re jsicpdrysizq')
    input.append('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd')
    input.append('de kr kd eoya kw aej tysr re ujdr lkgc jv')
    output.append('our language is impossible to understandqz')
    output.append('there are twenty six factorial possibilities')
    output.append('so it is okay if you want to just give up')
    for i in range(3):
        for pos in range(len(input[i])):
            if not dictionary.has_key(input[i][pos]):
                dictionary.update({input[i][pos]:output[i][pos]})
    print dictionary

def translate(text):
    ret = ''
    for item in text:
        ret += dictionary[item]
    return ret

def main():
    init()
    fin = open('input.dat', 'r')
    fout = open('output.dat', 'w')
    T = int(fin.readline())
    for i in range(T):
        googlerese = fin.readline()[:-1]
        english = translate(googlerese)
        fout.write('Case #{0}: {1}\n'.format(i + 1, english))
    return

if __name__ == '__main__':
    main()
