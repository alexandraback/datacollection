from sys import stdin

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args

def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):
        N = int(stdin.readline().strip())

        bffs_in = (map(int, stdin.readline().strip().split()))

        bffs_map = {kid + 1: bff for kid, bff in enumerate(bffs_in)}

        # reverse_bffs is a map int -> [int] because a kid can be popular
        reverse_bffs_map = {}
        for kid, bff in enumerate(bffs_in):
            if not bff in reverse_bffs_map:
                reverse_bffs_map[bff] = [kid + 1]
            else:
                reverse_bffs_map[bff].append(kid + 1)

        # debug_print("map 1", bffs_map)
        # debug_print("map 2", reverse_bffs_map)

        # Assign kids into clusters
        unlooked_kids = set(range(1, N + 1))
        clusters = []

        while len(unlooked_kids) > 0:

            cluster = set()

            kid = unlooked_kids.pop()
            kids_to_absorb = set([kid])

            while len(kids_to_absorb) > 0:

                kid_to_absorb = kids_to_absorb.pop()

                new_kid_1 = bffs_map[kid_to_absorb]
                if new_kid_1 in unlooked_kids:
                    unlooked_kids.remove(new_kid_1)
                    kids_to_absorb.add(new_kid_1)

                if kid_to_absorb in reverse_bffs_map:
                    more_kids = reverse_bffs_map[kid_to_absorb]
                    for more_kid in more_kids:
                        if more_kid in unlooked_kids:
                            unlooked_kids.remove(more_kid)
                            kids_to_absorb.add(more_kid)

                cluster.add(kid_to_absorb)

            clusters.append(cluster)

        debug_print("clusters", clusters)

        # Now score clusters
        # Each cluster result: (bool,max_circle_size)
        # True = pure cycle >= 3. size is size
        # False = otherwise. Then size is max size of 2ppl + hangers
        cycles = []
        chains = []

        for cluster in clusters:
            # Find length of longest cycle in cluster
            seen = []
            current = next(iter(cluster))
            while current not in seen:
                seen.append(current)
                current = bffs_map[current]

            duplicate_index = seen.index(current)
            cycle_length = len(seen) - duplicate_index
            cycles.append(cycle_length)
            debug_print('found_cycle_of_length', cycle_length, cluster)

            if cycle_length >= 3:
                continue

            # Find buddies
            current = next(iter(cluster))

            while not current == bffs_map[bffs_map[current]]:
                # print current, bffs_map[bffs_map[current]]
                current = bffs_map[current]

            buddies = (current, bffs_map[current])
            debug_print("buddies", buddies)

            chain_1 = 0
            chain_2 = 0
            for dude in cluster:
                chain_length = 0

                while not dude in buddies:
                    dude = bffs_map[dude]
                    chain_length += 1

                if dude == buddies[0]:
                    chain_1 = max(chain_length, chain_1)
                else:
                    chain_2 = max(chain_length, chain_2)

            chains.append(2 + chain_1 + chain_2)
            debug_print("added chain", cluster, chains)

        max_cycle = max(cycles) if len(cycles) else 0
        best_chains = sum(chains) if len(chains) else 0

        best_circle = max(max_cycle, best_chains)

        print "Case #{}: {}".format(case, best_circle)

if __name__ == "__main__":
    main()
