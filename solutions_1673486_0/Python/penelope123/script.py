import sys
from decimal import Decimal

from string import maketrans   # Required to call maketrans function.

def main(raw_data):
    data = []
    for line in raw_data:
        data.append(line.strip())
        
    T = data.pop(0)
    for i in range(int(T)):
        a, b = data.pop(0).split(' ')
        probs = data.pop(0).split(' ')
        a = Decimal(a)
        b = Decimal(b)
        rt = None
        prob_list = []
        for p in probs:
            if not rt:
                rt = Decimal(p)
            else:
                rt = rt * Decimal(p)
            prob_list.append(rt)
            
        min_keystrokes = Decimal(b + 2) #pressing enter
        for j, p in enumerate(prob_list):
            backspaces = a-(j+1)
            keystrokes_if_right = (b-a)+1+(backspaces*2)
            keystrokes_if_wrong = keystrokes_if_right + b + 1
            keystrokes = (keystrokes_if_right * p) + (keystrokes_if_wrong*(1-p))
            if keystrokes < min_keystrokes:
                min_keystrokes = keystrokes
                
        print "Case #%s: %s" %(i+1, min_keystrokes.quantize(Decimal('.000001')))
        
        
if __name__ == "__main__":
    main(sys.stdin)
