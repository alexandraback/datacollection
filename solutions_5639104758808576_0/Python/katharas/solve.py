
def create_people_list(shyness):
    people = []
    for s, count in enumerate(shyness):
        people.extend([s]*count)
    return sorted(people)

def solve(shyness):
    invited = 0
    standing = 0
    people = create_people_list(shyness)
    for s in people:
        if standing < s:
            invites = s-standing
            invited += invites
            standing += invites
        standing += 1
    return invited

T = int(raw_input())
for t in range(1, T+1):
    print "Case #%d: %d" % (
        t,
        solve(
            map(int, raw_input().split()[1])
        )
    )
