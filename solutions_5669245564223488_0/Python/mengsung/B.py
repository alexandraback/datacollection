import math

def isValid(strings) :
    s = ''.join(strings)
    
    appear = set()
    pre = None

    for c in s :
        if pre is not None and c != pre:
            if c in appear :
                return False
        appear.add(c)
        pre = c
        
    return True

def merge_char(string) :
    pre = None
    res = []
    for c in string :
        if pre is None or pre != c :
            res.extend(c)
        pre = c
    return ''.join(res)


def recursive(processed_strings, remaining_strings, slots, free) :
    count = 0
    if remaining_strings == [] :
        if isValid(processed_strings) :
            count = math.factorial(slots + free)
    else :
        for i in range(len(remaining_strings)) :
            s = remaining_strings.pop(i)

            if processed_strings == [] or s[0] != processed_strings[-1][-1] :
                if isValid(processed_strings) :
                    processed_strings.append(s)
                    count += recursive(processed_strings, remaining_strings, slots + 1, free)
                    processed_strings.pop()
    
            else :
                if isValid(processed_strings) :
                    processed_strings.append(s)
                    count += recursive(processed_strings, remaining_strings, slots, free)
                    processed_strings.pop()
            remaining_strings.insert(i, s)
    return count
    
    
def solve(f) :
    n = int(f.readline())
    strings = f.readline().strip().split(' ')
    strings = [ merge_char(s) for s in strings ]

    free = set()

    for i in range(n) :
        flag = 1
        for j in range(n) :
            if i != j and len(set(strings[i]) & set(strings[j])) > 0 :
                flag = 0
                break
        if flag == 1 :
            free.add(i)

    remaining_strings = []
    for i in range(n) :
        if i not in free :
            remaining_strings.append(strings[i])
    return recursive([],remaining_strings, 0, len(free)) % 1000000007

        

if __name__ == '__main__' :
    with open('B-small-attempt2.in') as f:
        t = int(f.readline())
        for i in range(t) :
            print ('Case #{0}: {1}'.format(i + 1, solve(f)))
