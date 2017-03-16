
import string

def split_state(state):
    if state == "-":
        return "+"
    else:
        return "-"

def main():

    test_case = int(raw_input())
    for i in range(0, test_case):
        pancace_stack = raw_input()
        state = pancace_stack[0]
        count = 1
        for e in pancace_stack:
            if e != state:
                count += 1
                state = split_state(state)
        if state == "+" and count > 0:
            count -= 1
        print ("Case #"+str(i+1)+": "+str(count))



if __name__ == "__main__":
    main()
