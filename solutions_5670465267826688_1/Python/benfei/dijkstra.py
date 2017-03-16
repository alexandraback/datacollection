"""Code jam 2015, Qualification Round
Problem C. Dijkstra
autor: benfei
"""

def mult(ijk_seq):
    mult_board = {
        "11": "1", "1i": "i", "1j": "j", "1k": "k",
        "i1": "i", "ii": "-1", "ij": "k", "ik": "-j",
        "j1": "j", "ji": "-k", "jj": "-1", "jk": "i",
        "k1": "k", "ki": "j", "kj": "-i", "kk": "-1",
    }
    
    mult_res = [ijk_seq[0]] + [""] * (len(ijk_seq) - 1)
    for m, curr in enumerate(ijk_seq[1:], 1):
        prev = mult_res[m-1]
        dprev = prev.replace("-", "")
        sprev = prev.count("-")
        dcurr = curr.replace("-", "")
        scurr = curr.count("-")
        snext = (sprev + scurr) % 2
        dnext = mult_board[dprev + dcurr]
        if snext:
           dnext = "-" + dnext
        dnext = dnext.replace("--", "")
        mult_res[m] = dnext
    
    return mult_res

def ijk_eq(ijk_seq):
    mult_board = {
        "11": "1", "1i": "i", "1j": "j", "1k": "k",
        "i1": "i", "ii": "-1", "ij": "k", "ik": "-j",
        "j1": "j", "ji": "-k", "jj": "-1", "jk": "i",
        "k1": "k", "ki": "j", "kj": "-i", "kk": "-1",
    }
    
    res = "1"
    for n_i, An in enumerate(ijk_seq):
        dprev = res.replace("-", "")
        sprev = res.count("-")
        dcurr = An.replace("-", "")
        scurr = An.count("-")
        snext = (sprev + scurr) % 2
        dnext = mult_board[dprev + dcurr]
        if snext:
           dnext = "-" + dnext
        dnext = dnext.replace("--", "")
        res = dnext
        if res == "i":
            break
    else:
        return False
    
    ijk_seq = ijk_seq[n_i+1:]
    res = "1"
    for n_j, An in enumerate(ijk_seq):
        dprev = res.replace("-", "")
        sprev = res.count("-")
        dcurr = An.replace("-", "")
        scurr = An.count("-")
        snext = (sprev + scurr) % 2
        dnext = mult_board[dprev + dcurr]
        if snext:
           dnext = "-" + dnext
        dnext = dnext.replace("--", "")
        res = dnext
        if res == "j":
            break
    else:
        return False
        
    ijk_seq = ijk_seq[n_j+1:]
    res = "1"
    for An in ijk_seq:
        dprev = res.replace("-", "")
        sprev = res.count("-")
        dcurr = An.replace("-", "")
        scurr = An.count("-")
        snext = (sprev + scurr) % 2
        dnext = mult_board[dprev + dcurr]
        if snext:
           dnext = "-" + dnext
        dnext = dnext.replace("--", "")
        res = dnext
    
    if res == "k":
        return True
        
    return False
    
    
def ijk_eq2(ijk_seq):
    mult_left = mult(ijk_seq)
    if mult_left[-1] != "-1":
        return False
        
    ind_i = min((ind for ind, x in enumerate(mult_left) if x == "i"), default=-1)
    if ind_i == -1:
        return False
    
    ijk_seq = ijk_seq[ind_i+1:]
    mult_left = mult(ijk_seq)
    ind_j = min((ind for ind, x in enumerate(mult_left) if x == "j"), default=-1)
    if ind_i == -1:
        return False
        
    ijk_seq = ijk_seq[ind_j+1:]
    mult_left = mult(ijk_seq)
    if mult_left[-1] != "k":
        return False
    
    return True
    
def parse_input():
    L, X = input().split(" ")
    L = int(L)
    X = int(X)
    ijk_seq = input()
    assert len(ijk_seq) == L, "The given ijk seq. must have exactly L letters"

    return ijk_seq, X

def print_result(x, y):
    y = "YES" if y else "NO"
    print("Case #{x:d}: {y}".format(x=x, y=y))

def main():
    T = int(input())
    for test_case in range(1, T+1):
        ijk_seq, X = parse_input()
        X_ORG = X
        X = min(X, 4 + (X % 4))
        is_eq = ijk_eq(ijk_seq * X)
        # assert is_eq == ijk_eq2(ijk_seq * X_ORG), "Case #{0:d}: {1}, {2}".format(test_case, is_eq, ijk_eq2(ijk_seq * X_ORG))
        print_result(test_case, is_eq)

if __name__ == "__main__":
    main()