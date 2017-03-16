In [1]: mapping = {}

In [2]: import string

In [3]: 's'.upper()
Out[3]: 'S'

In [4]: string.
string.Formatter        string.atol_error       string.index_error      string.printable        string.strip
string.Template         string.capitalize       string.join             string.punctuation      string.swapcase
string.ascii_letters    string.capwords         string.joinfields       string.replace          string.translate
string.ascii_lowercase  string.center           string.letters          string.rfind            string.upper
string.ascii_uppercase  string.count            string.ljust            string.rindex           string.uppercase
string.atof             string.digits           string.lower            string.rjust            string.whitespace
string.atof_error       string.expandtabs       string.lowercase        string.rsplit           string.zfill
string.atoi             string.find             string.lstrip           string.rstrip           
string.atoi_error       string.hexdigits        string.maketrans        string.split            
string.atol             string.index            string.octdigits        string.splitfields      

In [4]: string.ascii_lowercase
Out[4]: 'abcdefghijklmnopqrstuvwxyz'

In [5]: for c in string.ascii_lowercase:
   ...:     mapping[c] = c.upper()
   ...: 

In [6]: mapping
Out[6]: 
{'a': 'A',
 'b': 'B',
 'c': 'C',
 'd': 'D',
 'e': 'E',
 'f': 'F',
 'g': 'G',
 'h': 'H',
 'i': 'I',
 'j': 'J',
 'k': 'K',
 'l': 'L',
 'm': 'M',
 'n': 'N',
 'o': 'O',
 'p': 'P',
 'q': 'Q',
 'r': 'R',
 's': 'S',
 't': 'T',
 'u': 'U',
 'v': 'V',
 'w': 'W',
 'x': 'X',
 'y': 'Y',
 'z': 'Z'}

In [7]: mapping['a'] = 'y'

In [8]: mapping['o'] = 'e'

In [9]: mapping['z'] = 'q'

In [10]: i = 'ejp mysljylc kd kxveddknmc re jsicpdrysi'

In [11]: o = 'our language is impossible to understand'

In [12]: zip(i,o)
Out[12]: 
[('e', 'o'),
 ('j', 'u'),
 ('p', 'r'),
 (' ', ' '),
 ('m', 'l'),
 ('y', 'a'),
 ('s', 'n'),
 ('l', 'g'),
 ('j', 'u'),
 ('y', 'a'),
 ('l', 'g'),
 ('c', 'e'),
 (' ', ' '),
 ('k', 'i'),
 ('d', 's'),
 (' ', ' '),
 ('k', 'i'),
 ('x', 'm'),
 ('v', 'p'),
 ('e', 'o'),
 ('d', 's'),
 ('d', 's'),
 ('k', 'i'),
 ('n', 'b'),
 ('m', 'l'),
 ('c', 'e'),
 (' ', ' '),
 ('r', 't'),
 ('e', 'o'),
 (' ', ' '),
 ('j', 'u'),
 ('s', 'n'),
 ('i', 'd'),
 ('c', 'e'),
 ('p', 'r'),
 ('d', 's'),
 ('r', 't'),
 ('y', 'a'),
 ('s', 'n'),
 ('i', 'd')]

In [13]: 

In [13]: mapping.update(zip(i,o))

In [14]: mapping
Out[14]: 
{' ': ' ',
 'a': 'y',
 'b': 'B',
 'c': 'e',
 'd': 's',
 'e': 'o',
 'f': 'F',
 'g': 'G',
 'h': 'H',
 'i': 'd',
 'j': 'u',
 'k': 'i',
 'l': 'g',
 'm': 'l',
 'n': 'b',
 'o': 'e',
 'p': 'r',
 'q': 'Q',
 'r': 't',
 's': 'n',
 't': 'T',
 'u': 'U',
 'v': 'p',
 'w': 'W',
 'x': 'm',
 'y': 'a',
 'z': 'q'}

In [15]: i='rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'

In [16]: o='there are twenty six factorial possibilities'

In [17]: mapping.update(zip(i,o))

In [18]: i='de kr kd eoya kw aej tysr re ujdr lkgc jv'

In [19]: o='so it is okay if you want to just give up'

In [20]: mapping.update(zip(i,o))

In [21]: mapping
Out[21]: 
{' ': ' ',
 'a': 'y',
 'b': 'h',
 'c': 'e',
 'd': 's',
 'e': 'o',
 'f': 'c',
 'g': 'v',
 'h': 'x',
 'i': 'd',
 'j': 'u',
 'k': 'i',
 'l': 'g',
 'm': 'l',
 'n': 'b',
 'o': 'k',
 'p': 'r',
 'q': 'Q',
 'r': 't',
 's': 'n',
 't': 'w',
 'u': 'j',
 'v': 'p',
 'w': 'f',
 'x': 'm',
 'y': 'a',
 'z': 'q'}

In [22]: for i,o in mapping.iteritems():
   ....:     if o.isupper():
   ....:         print i,o
   ....: 
q Q

In [23]: sorted(mapping.values())
Out[23]: 
[' ',
 'Q',
 'a',
 'b',
 'c',
 'd',
 'e',
 'f',
 'g',
 'h',
 'i',
 'j',
 'k',
 'l',
 'm',
 'n',
 'o',
 'p',
 'q',
 'r',
 's',
 't',
 'u',
 'v',
 'w',
 'x',
 'y']

In [24]: ''.join(sorted(mapping.values()))
Out[24]: ' Qabcdefghijklmnopqrstuvwxy'

In [25]: mapping['q'] = 'z'

In [26]: open('/home/inada-n/Downloads/A
/home/inada-n/Downloads/A-small-attempt0.in  /home/inada-n/Downloads/ADT-12.0.0.zip       /home/inada-n/Downloads/APC-3.1.9.tgz

In [26]: input = open('/home/inada-n/Downloads/A-small-attempt0.in').readlines()

In [27]: input[0]
Out[27]: '30\n'

In [28]: input[1]
Out[28]: 'ejp mysljylc kd kxveddknmc re jsicpdrysi\n'

In [29]: fo = open('A-small.out','w')

In [30]: for i,case in enumerate(input[1:]):
   ....:     case = case.strip()
   ....:     print >>fo, "Case #" + str(i+1) + ':', ''.join(mapping[c] for c in case)
   ....: 

In [31]: !vim A-small.out

In [32]: fo.close()


