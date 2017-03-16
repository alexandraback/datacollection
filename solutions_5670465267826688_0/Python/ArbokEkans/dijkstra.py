class quat:
    ONE = 1
    I = 2
    J = 3
    K = 4
    d = { "1" : ONE, "i" : I, "j" : J, "k" : K }
    dinv = {v: k for k, v in d.items()}

    def __init__(self, char, sgn = True):
        self.num = quat.d[char]
        self.sgn = sgn

    def __mul__(self, rhs):
        a, b = self.num, rhs.num
        pos = self.sgn==rhs.sgn
    
        
        
        if a == quat.ONE:
            return quat(quat.dinv[b], pos)
        if b == quat.ONE:
            return quat(quat.dinv[a], pos)


        if a == b:
            return quat("1", not pos)
        
        
        dd = {"ij": "k", "jk":"i", "ki":"j"}

        sa, sb = quat.dinv[a], quat.dinv[b]
        
        if sa + sb in dd:
            return quat(dd[sa + sb], pos)
        else:
            return quat(dd[sb + sa], not pos)

    def __str__(self):
        res = ""
        if not self.sgn:
            res += "-"
        res += quat.dinv[self.num]
        return res
    
    def __repr__(self):
        return self.__str__()


def solve_simple(ijks):
    curr = quat("1")

    NOT_FOUND = 0
    FOUND_I = 1
    FOUND_J = 2
    state = NOT_FOUND
    
    for letter in ijks:
        ltr_quat = quat(letter)
        curr = curr * ltr_quat
        if state == NOT_FOUND:
            if str(curr) == "i":
                state = FOUND_I
                curr = quat("1")

        elif state == FOUND_I:
            if str(curr) == "j":
                state = FOUND_J
                curr = quat("1")

    return "YES" if state == FOUND_J and str(curr) == "k" else "NO"
            

def main():
    T = int(input())

    for test in range(1, T+1):
        _, X = [int(i) for i in input().split()]
        period = input()
        print("Case #{}: {}".format(test, solve_simple(period*X)))

main()
