import gcj

digits = ["ZERO", 
           "ONE", 
           "TWO", 
         "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def solve(s) :
    #print("Solve", s)

    if s == "":
        return []

    for i in range(10):
        digit = digits[i]
        cont = True
        for dl in digit:
            if not dl in s:
                cont = False
                break
        #print(digit + " contains in " + s)

        if cont:
            filtered = s
            fail = False
            #print('Filter' + digit)
            for dl in digit:
                #print(filtered)
                ix = filtered.find(dl)
                if ix == -1:
                    fail = True
                    break
                filtered = filtered[:ix] + filtered[ix + 1:]
            
            if not fail:
                rest = solve(filtered)
                
                if rest is not None:
                    return rest + [i]

    return None




ifile, ofile = gcj.get_files('A')

T = int(ifile.readline().strip())
for t in range(T):
    s = ifile.readline().strip()
    ans = solve(s)
    gcj.print_answer(ofile, t, ''.join(map(str, sorted(ans))))