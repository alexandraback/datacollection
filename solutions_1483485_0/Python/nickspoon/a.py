# Python 3.2
# Usage: python a.py < input.in > out.txt

cases = int(input())
map = {
 'a':'y', 'b':'h', 'c':'e', 'd':'s', 'e':'o', 'f':'c', 'g':'v', 'h':'x',
 'i':'d', 'j':'u', 'k':'i', 'l':'g', 'm':'l', 'n':'b', 'o':'k', 'p':'r',
 'q':'z', 'r':'t', 's':'n', 't':'w', 'u':'j', 'v':'p', 'w':'f', 'x':'m',
 'y':'a', 'z':'q'}
for case in range(cases):
    inline = input()
    outline = ''
    for c in inline:
        if c == ' ':
            outline += ' '
        elif map[c] != '':
            outline += map[c]
        else:
            outline += c
    print("Case #{0}: {1}".format(case + 1, outline))
