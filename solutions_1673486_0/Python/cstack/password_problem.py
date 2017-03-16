import sys

def product(L):
    p = 1
    for i in L:
        p *= i
    return p

num_cases = int(sys.stdin.readline())

for case_num in range(num_cases):
    num_typed, password_length = (int(i) for i in sys.stdin.readline().split())
    probs = [float(p) for p in sys.stdin.readline().split()]
    keystrokes_give_up = 2 + password_length
    prob_right = product(probs)
    keystrokes_keep_typing = (password_length-num_typed+1)*prob_right + (1-prob_right)*(password_length*2-num_typed+2)
    keystrokes_backspace = keystrokes_keep_typing
    prob_right = 1
    for num_backspaces in range(num_typed-1,0,-1):
        prob_right *= probs[num_typed-num_backspaces-1]
        keystrokes_backspace = min(keystrokes_backspace, (password_length-num_typed+num_backspaces*2+1)*prob_right + (1-prob_right)*(password_length*2-num_typed+num_backspaces*2+2))
    print "Case #"+str(case_num+1)+":", float(min(keystrokes_give_up, keystrokes_keep_typing, keystrokes_backspace))
