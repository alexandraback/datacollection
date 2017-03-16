t = int(raw_input())  # read a line with a single integer
result = ""

def happy(the_pancake_stack):
    for side in the_pancake_stack:
        if side == "-":
            return False
    return True

for i in xrange(1, t + 1):
  the_pancake_stack =  str(raw_input())
  flips = 0

  while not happy(the_pancake_stack):
    first_pancake_state = the_pancake_stack[0]
    j = 0 #Here 'j' is the number of pancakes on the top of the stack with same side facing as the first
    while the_pancake_stack[j] == first_pancake_state:
        if j == len(the_pancake_stack) - 1: break
        j += 1
    if first_pancake_state == "+":
        the_pancake_stack = (j+1)*"-" + the_pancake_stack[j+1:]
    else:
        the_pancake_stack = (j+1)*"+" + the_pancake_stack[j+1:]
    flips += 1

  result = result + "Case #{}: {}\n".format(i, flips)


#print result
file_name = "output.txt"
text_file = open(file_name, "w")
text_file.write(result)
