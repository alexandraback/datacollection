import fileinput

def steps_to_mote(my_mote, next_mote):
    steps = 0
    while my_mote <= next_mote:
        my_mote = my_mote+my_mote-1
        steps += 1
    return steps,my_mote

def solve_motes(my_mote, existing_motes):
    if len(existing_motes) == 0:
        return 0
    if my_mote < 2:
        return len(existing_motes)
    next_mote = existing_motes[0]
    if my_mote > next_mote:
        return solve_motes(my_mote+next_mote,existing_motes[1:])
    
    (steps,enlarged) = steps_to_mote(my_mote, next_mote)
    remaining_motes = len(existing_motes)
    steps_by_adding = steps + solve_motes(enlarged+next_mote, existing_motes[1:])
    if steps_by_adding > remaining_motes:
        return remaining_motes

    return steps_by_adding

#print solve_motes(2,[1,2])
#print solve_motes(2,[1,1,2,6])
#print solve_motes(10,[9,20,25,100])
#print solve_motes(1,[1,1,1,1])


def main():
    it = fileinput.input()
    num_cases = int(it.next())
    for i in range(num_cases):
        my_mote,num_motes = [int(x) for x in it.next().split()]
        motes = sorted([int(x) for x in it.next().split()])
        print "Case #%d: %d" % (i+1, solve_motes(my_mote,motes))

if __name__ == "__main__":
    main()

    
