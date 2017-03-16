#!/usr/bin/python3

from codejam import CodeJam

def docase(f):
    s = f.readline().strip()
    word = s[0]
    for ch in s[1:]:
        if ch < word[0]:
            word += ch
        else:
            word = ch + word
    return word


cj = CodeJam(docase)

# After importing cj into an interactive terminal, I test the code by
# running:
# >>> cj.processtext("""examples""")
#
# Then after downloading the problem set, I solve it with:
# >>> cj.processfile('filename')
