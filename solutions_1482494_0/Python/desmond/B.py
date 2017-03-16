class TooBadError(Exception):
    pass

def minimize(L):
    '''(list) -> int
    Given a list of levels in the game, calculate the minimum number
    of times Ryan will need to play through a level to complete all
    of the levels with 2 stars.
    '''
    runs_and_stars = [0, 0]
    
    L = sorted(L, key=lambda level: level[1], reverse=True)
    L = sorted(L, key=lambda level: level[0], reverse=True)
    
    while L:
        L, runs_and_stars = get_twostars(L, runs_and_stars)
        L, runs_and_stars =  get_onestars(L, runs_and_stars)
    print L
    print runs_and_stars
    return runs_and_stars[0]
        
def get_twostars(L, rs):
    next = len(L) - 1
    while L and rs[1] >= L[next][0]:
        if len(L.pop()) > 1:
            rs[1] += 2
        else:
            rs[1] += 1
        rs[0] += 1
        next -= 1
    return L, rs
        
def get_onestars(L, rs):
    if L:
        needed_stars = L[len(L) - 1][0]
        next = len(L) - 1
        
        while L and rs[1] < needed_stars and next >= 0:
            if len(L[next]) < 2 or rs[1] < L[next][1]:
                next -= 1
            else:
                L[next].pop()
                rs[0] += 1
                rs[1] += 1
                next -= 1
                
        if rs[1] < needed_stars:
            raise TooBadError
        
    return L, rs

    
if __name__ == "__main__":
    f = open('B-example.txt')
    num_test_cases = int(f.readline())
    c = 0
    
    output = open('B-example-output.txt', 'w')
    
    while c < num_test_cases:
        num_levels = int(f.readline())
        levels = []
        while len(levels) < num_levels:
            i, j = f.readline().split()
            levels.append([int(j), int(i)])
        
        try:    
            minimum_runs = minimize(levels)
        except TooBadError:
            minimum_runs = "Too Bad"
        
        case_output = "Case #{}: {}" .format(c + 1, minimum_runs)
        output.write(case_output + '\n')
        
        c += 1