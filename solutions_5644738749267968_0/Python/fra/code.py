#!/usr/bin/python

import sys


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        nb_blocks = int(data.readline())
        N = map(float, data.readline().split())
        K = map(float, data.readline().split())
        N_copy = list(N)
        K_copy = list(K)

        # WAR
        # naomie takes random block
        # ken takes nearest block above, or the lowest if he hasn't any
        n_points_war = 0
        while len(N) > 0:
            n = N.pop()
            smallest_dif = None
            smallest_block_idx = -1
            for ik, k in enumerate(K):
                dif = k - n
                if dif > 0:
                    if smallest_dif is None or dif < smallest_dif:
                        smallest_dif = dif
                        smallest_block_idx = ik
            if smallest_dif is None:
                n_points_war += 1
                k = min(K)
                K.remove(min(K))
            else:
                k = K[smallest_block_idx]
                K = K[:smallest_block_idx] + K[smallest_block_idx + 1:]

        # DECEIT
        # new algo:
        # on demande toujours un truc plus gros que le plus gros que K
        # donc K va mettre son plus petit
        # et du coup on mets notre plus petit plus grand que son petit

        N = N_copy
        K = K_copy
        n_points_deceit = 0
        while len(N) > 0:
            # n asked:
            # n_wished = max(K) + 0.00001 # TODO
            k = min(K)
            # find smallest n above k
            smallest_dif = None
            smallest_block_idx = -1
            for ik, n in enumerate(N):
                dif = n - k
                if dif > 0:
                    if smallest_dif is None or dif < smallest_dif:
                        smallest_dif = dif
                        smallest_block_idx = ik
            if smallest_dif is None:
                # we don't have any, we shouldn't have asked that
                # so we ask him to drop it's hight number
                # n_wished = max(K) - 0.00001 # TODO
                k = max(K)
                n = min(N)
            else:
                n = N[smallest_block_idx]
                n_points_deceit += 1

            #d1 = n_wished - k
            #d2 = n - k
            #if (d1 < 0 and d2 < 0) or (d1 > 0 and d2 > 0):
            #    pass
            #else:
            #    print "CHEAT"
            N.remove(n)
            K.remove(k)
            # print "N:", n, "K:", k, "NTold:", n_wished

        print "Case #%d: %d %d" % (icase + 1, n_points_deceit, n_points_war)


if __name__ == "__main__":
    main()
