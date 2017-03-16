import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))

quat_tbl = {'1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
            'i': {'1': 'i', 'i': '-1', 'j': 'k', 'k': '-j'},
            'j': {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i'},
            'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'}}

times_to_none = {'1': None, 'i': 2, 'j': 2, 'k': 2, '-1': 1, '-i': 2, '-j': 2, '-k': 2}

def mul_quat(a, b):
    if a[0] == '-':
        if b[0] == '-':
            return quat_tbl[a[1]][b[1]]
        else:
            res = quat_tbl[a[1]][b]
            if res[0] == '-':
                return res[1]
            else:
                return '-' + res
    else:
        if b[0] == '-':
            res = quat_tbl[a][b[1]]
            if res[0] == '-':
                return res[1]
            else:
                return '-' + res
        else:
            return quat_tbl[a][b]

def do_calc(i):
    params = map(int, string.split(string.strip(testcase.readline())))
    l = params[0]
    x = params[1]
    letters = string.strip(testcase.readline())
    #print "letters", letters
    val_letters = letters[0]
    #print val_letters
    for char in letters[1:]:
        val_letters = mul_quat(val_letters, char)
        #print val_letters
    #print "val_letters", val_letters
    ttnone = times_to_none[val_letters]
    #print "ttnone", ttnone
    if ttnone == None or x%ttnone != 0 or x%(ttnone*2) == 0:
        return "NO"
    i_idx = []
    oneiter = letters*ttnone
    if x*l > len(oneiter):
        fulliter = 2*oneiter
    else:
        fulliter = oneiter
    val_letters = '1'
    for idx, char in enumerate(fulliter):
        val_letters = mul_quat(val_letters, char)
        if val_letters == 'i':
            i_idx.append(idx)
    #print "i_idx", i_idx
    if len(i_idx) == 0:
        return "NO"
    for iidx in i_idx:
        val_letters = '1'
        if len(oneiter) != l*x:
            if iidx > len(oneiter):
                if 5*len(oneiter) <= l*x:
                    fulliter = 5*oneiter
                else:
                    fulliter = 3*oneiter
            else:
                fulliter = 3*oneiter
            for idx, char in enumerate(fulliter):
                if idx <= iidx:
                    continue
                val_letters = mul_quat(val_letters, char)
                if val_letters == 'j':
                    return "YES"
        else:
            for idx, char in enumerate(oneiter):
                if idx<= iidx:
                    continue
                val_letters = mul_quat(val_letters, char)
                if val_letters == 'j':
                    return "YES"
    return "NO"
        

for i in xrange(1, num_cases+1):
    res = do_calc(i)
    print "Case #"+str(i)+": "+res
