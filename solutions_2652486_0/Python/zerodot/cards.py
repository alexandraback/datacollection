


def get_sets(s):
    return [int(e) for e in s.split()]


def guess(s):
    #let's try unique products first
    if 5*5*5 in s: return "555"
    if 4*5*5 in s: return "455"
    if 4*4*5 in s: return "445"
    if 4*4*4 in s: return "444"
    if 3*5*5 in s: return "355"
    if 3*4*5 in s: return "345"
    if 3*4*4 in s: return "344"
    if 3*3*5 in s: return "335"
    if 3*3*4 in s: return "334"
    if 3*3*3 in s: return "333"
    if 2*5*5 in s: return "255"
    if 2*4*5 in s: return "245"
    if 2*4*4 in s: return "244"
    if 2*3*5 in s: return "235"
    if 2*3*4 in s: return "234"
    if 2*3*3 in s: return "245"
    if 2*2*4 in s: return "224"
    #that'll do it: 17/20 cases, 1-(7/8)^7 chance of a hit = 0.5162084817886352
    else: return "222"

if __name__=='__main__':
    input() #T=1
    input() #R,M,N,K=100,3,5,7
    print("Case #1:")
    for i in range(100):
        print(guess(get_sets(input())))
    
