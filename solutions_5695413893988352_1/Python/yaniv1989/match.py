import sys

def fill_with(s, start, end, c):
    new_s = ""
    for k in xrange(start, end):
        if s[k] == '?':
            new_s += c
        else:
            new_s += s[k]
    return new_s

def fill_with2(s, s2, start, end, c):
    new_s = ""
    new_s2 = ""
    for k in xrange(start, end):
        if (s[k] == '?') and (s2[k] == '?'):
            new_s += c
            new_s2 += c
        elif (s[k] == '?'):
            new_s += s2[k]
            new_s2 += s2[k]
        elif (s2[k] == '?'):
            new_s += s[k]
            new_s2 += s[k]
        else:
            new_s += s[k]
            new_s2 += s2[k]
    return new_s, new_s2

def get_min_gap(s1, s2, b, s1_larger):
    new_s1, new_s2 = fill_with2(s1, s2, 0, b, '0')
    if s1_larger:
        new_s1 += fill_with(s1, b, len(s1), '0')
        new_s2 += fill_with(s2, b, len(s2), '9')
    else:
        new_s1 += fill_with(s1, b, len(s1), '9')
        new_s2 += fill_with(s2, b, len(s2), '0')
    return new_s1, new_s2

def get_best(old_s1, old_s2, new_s1, new_s2):
    if old_s1 == -1:
        return new_s1, new_s2
    curr_diff = abs(int(old_s1)-int(old_s2))
    new_diff = abs(int(new_s1)-int(new_s2))
    if ((new_diff < curr_diff) or ((new_diff == curr_diff) and ((new_s1 < old_s1) or ((new_s1 == old_s1) and (new_s2 < old_s2))))):
        return new_s1, new_s2
    return old_s1, old_s2

def f(s1, s2):
    is_eq = True
    for i in xrange(len(s1)):
        if (s1[i] != s2[i]) and (s1[i] != '?') and (s2[i] != '?'):
            is_eq = False
            pos = i
            break

    if is_eq:
        new_s = ""
        for i in xrange(len(s1)):
            if (s1[i] == '?') and (s2[i] == '?'):
                new_s += '0'
            else:
                if s1[i] != '?':
                    new_s += s1[i]
                else:
                    new_s += s2[i]

        return new_s, new_s

    best_s1, best_s2 = -1, -1

    for b in xrange(0, pos):
        if (s1[b] == '?') and (s2[b] == '?'):
            new_s1, new_s2 = get_min_gap(s1[:b] + '1' + s1[b+1:], s2[:b] + '0' + s2[b+1:], b, True)
            best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)
            new_s1, new_s2 = get_min_gap(s1[:b] + '0' + s1[b+1:], s2[:b] + '1' + s2[b+1:], b, False)
            best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)
        elif s1[b] == '?':
            if s2[b] < '9':
                new_s1, new_s2 = get_min_gap(s1[:b] + chr(ord(s2[b])+1) + s1[b+1:], s2, b, True)
                best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)
            if s2[b] > '0':
                new_s1, new_s2 = get_min_gap(s1[:b] + chr(ord(s2[b])-1) + s1[b+1:], s2, b, False)
                best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)
        elif s2[b] == '?':
            if s1[b] < '9':
                new_s1, new_s2 = get_min_gap(s1, s2[:b] + chr(ord(s1[b])+1) + s2[b+1:], b, False)
                best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)
            if s1[b] > '0':
                new_s1, new_s2 = get_min_gap(s1, s2[:b] + chr(ord(s1[b])-1) + s2[b+1:], b, False)
                best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)

    new_s1, new_s2 = get_min_gap(s1, s2, pos, s1[pos]>s2[pos])
    best_s1, best_s2 = get_best(best_s1, best_s2, new_s1, new_s2)

    return best_s1, best_s2
    
    if s1[pos] > s2[pos]:
        reord = False
        larger = s1
        smaller = s2
    else:
        reord = True
        larger = s2
        smaller = s1
    new_smaller, new_larger = fill_with2(smaller, larger, 0, pos, '0')
    new_larger += fill_with(larger, pos, len(larger), '0')
    new_smaller += fill_with(smaller, pos, len(smaller), '9')

    best_diff = int(new_larger)-int(new_smaller)
    res = new_larger[:], new_smaller[:]
    if reord:
        res = res[::-1]

    found = False
    for i in xrange(pos-1, -1, -1):
        if smaller[i] == '?':
            new_smaller, new_larger = fill_with2(smaller, larger, 0, i, '0')
            if larger[i] == '?':
                new_smaller += '1'
                new_larger += '0'
            else:
                if larger[i] == '9':
                    continue
                new_smaller += chr(ord(larger[i])+1)
                new_larger += larger[i]
            new_smaller += fill_with(smaller, i+1, len(smaller), '0')
            new_larger += fill_with(larger, i+1, len(larger), '9')
            found = True
        elif larger[i] == '?':
            new_smaller, new_larger = fill_with2(smaller, larger, 0, i, '0')
            if smaller[i] == '0':
                continue
            new_smaller += smaller[i]
            new_larger += chr(ord(smaller[i])-1)
            new_smaller += fill_with(smaller, i+1, len(smaller), '0')
            new_larger += fill_with(larger, i+1, len(larger), '9')
            found = True
        if found:
            diff = int(new_smaller)-int(new_larger)
            new_res = new_larger[:], new_smaller[:]
            if reord:
                new_res = new_res[::-1]
            
            if (diff < best_diff) or ((diff == best_diff) and ((int(new_res[0]) < int(res[0])) or ((int(new_res[0]) == int(res[0])) and (int(new_res[1]) < int(res[1]))))):
                best_diff = diff
                res = new_res
            return res

    return res
        

    best_diff = 10**20
    for i in xrange(2):
        if i == 0:
            larger = s1
            smaller = s2
        else:
            larger = s2
            smaller = s1
            
        j = 0
        last_q = -1
        while (larger[j] == smaller[j]) or (larger[j] == '?') or (smaller[j] == '?'):
            if (larger[j] == '?') and (smaller[j] == '?'):                
                last_q = j
            elif (larger[j] == '?'):
                larger = larger[:j] + smaller[j] + larger[j+1:]
            elif (smaller[j] == '?'):
                smaller = smaller[:j] + larger[j] + smaller[j+1:]                
            j += 1

            new_larger = ""
            new_smaller = ""
            if larger[j] > smaller[j]:
                for k in xrange(j):
                    new_larger = fill_with(larger, 0, j, '0')
                    new_smaller = fill_with(smaller, 0, j, '0')      
            else:
                if last_q == -1:
                    continue
                new_larger = fill_with(larger, 0, last_q, '0')
                new_smaller = fill_with(smaller, 0, last_q, '0')      
                new_larger += '1'
                new_smaller += '0'
                j = last_q
            new_larger += fill_with(larger, j, len(larger), '0')
            new_smaller += fill_with(smaller, j, len(smaller), '9')

            diff = int(new_larger)-int(new_smaller)
            if diff < best_diff:
                best_diff = diff
                if i == 0:
                    res = new_larger, new_smaller
                else:
                    res = new_smaller, new_larger        
    return res
                    
if __name__ == "__main__":
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = "in.txt"

    if len(sys.argv) > 2:
        ofname = sys.argv[2]
    else:
        ofname = "out.txt"
                                                               
    
    inp = open(fname, "rb").read()
    inp = inp.splitlines()[1:]

    outp = open(r"out.txt", "wb")
    for i in xrange(len(inp)):
        cin = inp[i].split()
        cin = [cin[0].strip(), cin[1].strip()]
        r = " ".join(f(*cin))
        outp.write("Case #%d: " % (i+1) + r + "\r\n")        
        
    outp.close()


                
