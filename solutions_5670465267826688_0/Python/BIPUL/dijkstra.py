table = {
    '1':{
        '1':'1',
        'i':'i',
        'j':'j',
        'k':'k'
        },
    'i':{
        '1':'i',
        'i':'1',
        'j':'k',
        'k':'j'
        },
    'j':{
        '1':'j',
        'i':'k',
        'j':'1',
        'k':'i'
        },
    'k':{
        '1':'k',
        'i':'j',
        'j':'i',
        'k':'1'
        }
    }
minus = {
    '1':{
        '1':False,
        'i':False,
        'j':False,
        'k':False
        },
    'i':{
        '1':False,
        'i':True,
        'j':False,
        'k':True
        },
    'j':{
        '1':False,
        'i':True,
        'j':True,
        'k':False
        },
    'k':{
        '1':False,
        'i':False,
        'j':True,
        'k':True
        }
    }
def solve(string,L,X):
    sol = '1'
    stage = ['i','j','k','l']
    state = 0
    i = 0
    si = 0
    sign = False
    while i < X:
        si=0
        while si<L:
            s = string[si]
            sign = sign ^ minus[sol][s]
            sol = table[sol][s]
            if (not sign) and sol==stage[state]:
                sol = '1'
                state+=1
            si+=1
        i+=1
    #print(state,sol,sign)
    if state==3 and sign==False and sol=='1':
        return "YES"
    else:
        return "NO"
for t in range(int(input())):
    (L,X) = [int(s) for s in input().strip().split(" ")]
    string = input()
    print("Case #{0}: {1}".format(t+1,solve(string,L,X)))
