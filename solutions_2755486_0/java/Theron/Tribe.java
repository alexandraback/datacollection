package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Tribe implements Comparable<Tribe> {
    public int getDay() {
        return day;
    }

    private int id;
    private int day;
    private int numAttacks;
    private int west;
    private int east;
    private int strength;
    private final int deltaDay;
    private final int deltaEast;
    private final int deltaStrength;

    public Tribe(int id, int[] data) {
        this(id, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    }

    private Tribe(int id, int initialDay, int numAttacks, int initialWest, int initialEast, int initialStrength, int deltaDay, int deltaEast, int deltaStrength) {
        this.id = id;
        this.day = initialDay;
        this.numAttacks = numAttacks;
        this.west = initialWest;
        this.east = initialEast;
        this.strength = initialStrength;
        this.deltaDay = deltaDay;
        this.deltaEast = deltaEast;
        this.deltaStrength = deltaStrength;
    }

    public List<Attack> attack(Map<Integer, Integer> wall) {
        List<Attack> attacks = new ArrayList<Attack>();
        for (int i = west; i < east; i++) {
            Integer wallPiece = wall.get(i);
            if (wallPiece == null) wallPiece = 0;

            if (wallPiece < strength) {
                attacks.add(new Attack(i, strength));
            }
        }

        day += deltaDay;
        numAttacks--;
        west += deltaEast;
        east += deltaEast;
        strength += deltaStrength;

        return attacks;
    }

    public boolean isFinished()
    {
        return numAttacks <= 0;
    }

    @Override
    public int compareTo(Tribe tribe) {
        int comp = day-tribe.day;
        if (comp != 0) return comp;
        return id-tribe.id;
    }
}
